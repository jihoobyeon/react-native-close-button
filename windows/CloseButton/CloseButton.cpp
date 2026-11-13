#include "pch.h"

#include "CloseButton.h"
#include <winrt/Windows.Foundation.h>
#include <winrt/Microsoft.UI.Xaml.h>
#include <winrt/Microsoft.UI.Xaml.Controls.h>
#include <winrt/Microsoft.UI.Windowing.h>

namespace winrt::CloseButton
{
  using namespace winrt::Microsoft::UI::Xaml;

  void CloseButton::Initialize(React::ReactContext const &reactContext) noexcept {
    m_context = reactContext;
  }

  HWND getHwnd() { // https://stackoverflow.com/questions/75436438
    struct ProcessWindow { DWORD pid; HWND hwnd; } pw = {};
    pw.pid = GetCurrentProcessId();
    EnumWindows([](auto hwnd, auto lp) {
      DWORD pid;
      GetWindowThreadProcessId(hwnd, &pid);
      if (pid != ((ProcessWindow*)lp)->pid) return TRUE;
      ((ProcessWindow*)lp)->hwnd = hwnd;
      return FALSE;
      }, (LPARAM)&pw);

    return pw.hwnd;
  }

  void CloseButton::install() noexcept
  {
    m_context.UIDispatcher().Post([this]() {
      HWND hwnd = getHwnd();

      if (!hwnd || m_hwnd.load() == hwnd)
        return;

      m_hwnd.store(hwnd);

      SetWindowSubclass(
        m_hwnd,
        SubclassProc,
        reinterpret_cast<UINT_PTR>(this),
        reinterpret_cast<DWORD_PTR>(this)
      );
    });
  }

  void CloseButton::closeNow() noexcept
  {
    HWND hwnd = m_hwnd.load();

    if (!hwnd) return;

    m_allowClose = true;

    PostMessage(m_hwnd, WM_CLOSE, 0, 0);
  }

  LRESULT CALLBACK CloseButton::SubclassProc(
    HWND hwnd,
    UINT msg,
    WPARAM wParam,
    LPARAM lParam,
    UINT_PTR subclassId,
    DWORD_PTR refData
  )
  {
    auto self = reinterpret_cast<CloseButton*>(refData);

    switch (msg)
    {
      case WM_CLOSE:
      {
        if (self->m_allowClose)
        {
          self->m_allowClose = false;
          self->m_hwnd.store(nullptr);

          // 실제 창 닫기 허용
          return DefSubclassProc(
            hwnd, msg, wParam, lParam
          );
        }

        // JavaScript에 닫기 이벤트 전달
        if (self->onBeforeClose)
          self->onBeforeClose();

        // 기본 닫기 동작 차단
        return 0;
      }

      case WM_NCDESTROY:
      {
        // 창 파괴 시 Subclass 해제
        RemoveWindowSubclass(
          hwnd,
          SubclassProc,
          subclassId
        );

        self->m_hwnd.store(nullptr);

        return DefSubclassProc(
          hwnd, msg, wParam, lParam
        );
      }
    }

    return DefSubclassProc(hwnd, msg, wParam, lParam);
  }

} // namespace winrt::CloseButton

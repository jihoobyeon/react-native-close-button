#include "pch.h"

#include "RNCloseButton.h"
#include <winrt/Windows.Foundation.h>
#include <winrt/Microsoft.UI.Xaml.h>
#include <winrt/Microsoft.UI.Xaml.Controls.h>
#include <winrt/Microsoft.UI.Windowing.h>

namespace winrt::RNCloseButton
{
  using namespace winrt::Microsoft::UI::Xaml;

  void RNCloseButton::Initialize(React::ReactContext const &reactContext) noexcept {
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

  std::weak_ptr<RNCloseButton>WeakInstance;

  LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    if (msg == WM_CLOSE) {
      std::shared_ptr<RNCloseButton> pThis = WeakInstance.lock();
      if (pThis && pThis->toDo) pThis->toDo();
      return 0;
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
  }

  void RNCloseButton::doBeforeClose(std::function<void()> const& toDo) noexcept {
    this->toDo = toDo;
    SetWindowLongPtr(getHwnd(), GWLP_WNDPROC, (LONG_PTR)WindowProc);
    WeakInstance = shared_from_this();
    SetWindowLongPtr(getHwnd(), GWLP_USERDATA, (LONG_PTR)this);
  }

  void RNCloseButton::closeNow() noexcept {
    Window::Current().Close();
  }

} // namespace winrt::RNCloseButton

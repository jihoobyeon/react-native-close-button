#pragma once

#include "pch.h"
#include "resource.h"

#if __has_include("codegen\NativeCloseButtonDataTypes.g.h")
  #include "codegen\NativeCloseButtonDataTypes.g.h"
#endif
#include "codegen\NativeCloseButtonSpec.g.h"

#include "NativeModules.h"

namespace winrt::CloseButton
{
  REACT_TURBO_MODULE(CloseButton)
  struct CloseButton
  {
    using ModuleSpec = CloseButtonCodegen::CloseButtonSpec;

    REACT_INIT(Initialize)
      void Initialize(React::ReactContext const& context) noexcept;

    REACT_METHOD(install)
      void install() noexcept;

    REACT_METHOD(closeNow)
      void closeNow() noexcept;

    REACT_EVENT(onBeforeClose)
      std::function<void()> onBeforeClose;

    std::atomic<HWND> m_hwnd{ nullptr };
    std::atomic_bool m_allowClose{ false };

  private:
    static LRESULT CALLBACK SubclassProc(
      HWND hwnd,
      UINT msg,
      WPARAM wParam,
      LPARAM lParam,
      UINT_PTR subclassId,
      DWORD_PTR refData
    );

    React::ReactContext m_context;
  };
} // namespace winrt::CloseButton

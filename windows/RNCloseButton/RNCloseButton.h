#pragma once

#include "pch.h"
#include "resource.h"

#if __has_include("codegen\NativeRNCloseButtonDataTypes.g.h")
  #include "codegen\NativeRNCloseButtonDataTypes.g.h"
#endif
#include "codegen\NativeRNCloseButtonSpec.g.h"

#include "NativeModules.h"

namespace winrt::RNCloseButton
{
  REACT_MODULE(RNCloseButton)
  struct RNCloseButton : std::enable_shared_from_this<RNCloseButton>
  {
    using ModuleSpec = RNCloseButtonCodegen::RNCloseButtonSpec;

    REACT_INIT(Initialize)
    void Initialize(React::ReactContext const &reactContext) noexcept;

    REACT_METHOD(doBeforeClose)
    void doBeforeClose(std::function<void()> const& toDo) noexcept;

    REACT_EVENT(toDo)
    std::function<void()> toDo;

    REACT_METHOD(closeNow)
    void closeNow() noexcept;

    private:
      React::ReactContext m_context;
  };
} // namespace winrt::RNCloseButton

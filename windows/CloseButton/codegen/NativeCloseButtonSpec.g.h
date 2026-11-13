
/*
 * This file is auto-generated from a NativeModule spec file in js.
 *
 * This is a C++ Spec class that should be used with MakeTurboModuleProvider to register native modules
 * in a way that also verifies at compile time that the native module matches the interface required
 * by the TurboModule JS spec.
 */
#pragma once
// clang-format off


#include <NativeModules.h>
#include <tuple>

namespace CloseButtonCodegen {

struct CloseButtonSpec : winrt::Microsoft::ReactNative::TurboModuleSpec {
  static constexpr auto methods = std::tuple{
      Method<void() noexcept>{0, L"install"},
      Method<void() noexcept>{1, L"closeNow"},
      EventEmitter<void(void)>{2, L"onBeforeClose"},
  };

  template <class TModule>
  static constexpr void ValidateModule() noexcept {
    constexpr auto methodCheckResults = CheckMethods<TModule, CloseButtonSpec>();

    REACT_SHOW_METHOD_SPEC_ERRORS(
          0,
          "install",
          "    REACT_METHOD(install) void install() noexcept { /* implementation */ }\n"
          "    REACT_METHOD(install) static void install() noexcept { /* implementation */ }\n");
    REACT_SHOW_METHOD_SPEC_ERRORS(
          1,
          "closeNow",
          "    REACT_METHOD(closeNow) void closeNow() noexcept { /* implementation */ }\n"
          "    REACT_METHOD(closeNow) static void closeNow() noexcept { /* implementation */ }\n");
    REACT_SHOW_EVENTEMITTER_SPEC_ERRORS(
          2,
          "onBeforeClose",
          "    REACT_EVENT(onBeforeClose) std::function<void(void)> onBeforeClose;\n");
  }
};

} // namespace CloseButtonCodegen

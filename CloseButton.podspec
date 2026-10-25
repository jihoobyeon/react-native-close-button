require "json"

package = JSON.parse(File.read(File.join(__dir__, "package.json")))

Pod::Spec.new do |s|
  s.name         = "CloseButton"
  s.version      = package["version"]
  s.summary      = package["description"]
  s.homepage     = package["homepage"]
  s.license      = package["license"]
  s.authors      = package["author"]

  s.platforms    = { :osx => "10.15" }
  s.source       = { :git => "https://github.com/jihoobyeon/react-native-close-button.git", :tag => "#{s.version}" }

  s.source_files = "macos/*.{h,m,mm,cpp}"

  install_modules_dependencies(s)
end

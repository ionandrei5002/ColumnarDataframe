from conans import ConanFile, Meson

class HelloConan(ConanFile):
    name = "ColumnarDataframe"
    version = "0.1.0"
    settings = "os", "compiler", "build_type", "arch"
    generators = "pkg_config" , "json"
    exports_sources = "*"
    requires = "catch2/2.4.0@bincrafters/stable"
        
    def build(self):
        meson = Meson(self)
        meson.configure(
            source_folder="%s" % self.source_folder,
            build_folder=""
        )
        meson.build()

    def package_info(self):
        self.cpp_info.libs = ["ColumnarDataframe"]
from conans import ConanFile, CMake, tools


class DataStructureConan(ConanFile):
    name = "DataStructure"
    version = "1.0.0"
    license = "GPL License"
    author = "Olcay Taner Yildiz olcay.yildiz@ozyegin.edu.tr"
    url = "https://github.com/StarlangSoftware/DataStructure-CPP"
    description = "DataStructure Library"
    topics = ("")
    exports_sources = "src/*"
    no_copy_source = True

    def package(self):
        self.copy("*.h", dst="include", keep_path=False)

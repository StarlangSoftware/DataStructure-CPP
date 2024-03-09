from os.path import join

from conan import ConanFile
from conan.tools.files import copy


class DataStructureConan(ConanFile):
    name = "data_structure"
    version = "1.0.0"
    license = "GPL License"
    author = "Olcay Taner Yildiz olcay.yildiz@ozyegin.edu.tr"
    url = "https://github.com/StarlangSoftware/DataStructure-CPP"
    description = "DataStructure Library"
    topics = ("")
    exports_sources = "src/*"
    no_copy_source = True

    def package(self):
        copy(conanfile=self, keep_path=False, src=join(self.source_folder), dst=join(self.package_folder, "include"), pattern="*.h")

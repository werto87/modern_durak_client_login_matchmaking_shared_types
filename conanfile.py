from conans import ConanFile, CMake


class modern_durak_client_login_matchmaking_shared_types(ConanFile):
    name = "modern_durak_client_login_matchmaking_shared_types"
    license = "<Put the package license here>"
    url = "<Package recipe repository url here, for issues about the package>"
    description = "<Description of hello here>"
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False]}
    default_options = {"shared": False}
    generators = "cmake"
    exports_sources = "*"

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        self.copy("*.hxx", dst="modern_durak_client_login_matchmaking_shared_types",
                  src="modern_durak_client_login_matchmaking_shared_types")

    def package_info(self):
        self.cpp_info.libs = ["modern_durak_client_login_matchmaking_shared_types"]

    def package_id(self):
        self.info.header_only()

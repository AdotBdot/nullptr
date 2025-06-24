{
  description = "C/C++";

  inputs.nixpkgs.url = "https://flakehub.com/f/NixOS/nixpkgs/0.1";

  outputs =
    inputs:
    let
      supportedSystems = [
        "x86_64-linux"
        "aarch64-linux"
        "x86_64-darwin"
        "aarch64-darwin"
      ];
      forEachSupportedSystem =
        f:
        inputs.nixpkgs.lib.genAttrs supportedSystems (
          system:
          f {
            pkgs = import inputs.nixpkgs { inherit system; };
          }
        );
    in
    {
      devShells = forEachSupportedSystem (
        { pkgs }:
        {
          default =
            pkgs.mkShell.override
              {
                # Override stdenv in order to change compiler:
                stdenv = pkgs.clangStdenv;
              }
              {
                packages =
                  with pkgs;
                  [
                    xorg.libXi
                    xorg.libXext
                    xorg.libXcursor
                    xorg.libXinerama
                    xorg.libXrandr
                    libxkbcommon
                    pkg-config
                    xorg.libX11.dev
                    wayland
                    wayland.dev
                    wayland-scanner
                    libGL
                    libGLU
                    clang-tools
                    cmake
                    codespell
                    conan
                    cppcheck
                    doxygen
                    gtest
                    lcov
                    vcpkg
                    vcpkg-tool
                  ]
                  ++ (if system == "aarch64-darwin" then [ ] else [ gdb ]);
                shellHook = ''
                  export LD_LIBRARY_PATH=${pkgs.wayland}/lib:${pkgs.libxkbcommon}/lib:$LD_LIBRARY_PATH
                '';

              };
        }
      );
    };
}

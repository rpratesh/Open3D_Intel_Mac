// ----------------------------------------------------------------------------
// -                        Open3D: www.open3d.org                            -
// ----------------------------------------------------------------------------
// The MIT License (MIT)
//
// Copyright (c) 2018 www.open3d.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
// ----------------------------------------------------------------------------

#include <iostream>
#include <memory>
#include <thread>
#include <list> 
#include <fstream>

#include <Open3D/Open3D.h>

using namespace open3d;

/// Function to print the output to stdout in format specified in assignment.pdf
void print(std::vector<std::vector<int>> const connected_components)
{
	std::cout << "[";
    for (unsigned int i = 0; i < connected_components.size(); ++i)
    {
        std::cout << "[";
        unsigned int j;
        for (j = 0; j < connected_components[i].size()-1; ++j)
        {
            std::cout << connected_components[i][j] << ", ";
        }
        std::cout << connected_components[i][j];
        std::cout << "], ";
    }
    std::cout << "]";
    std::cout << std::endl;
}

/// Function to print the output to file in format specified in assignment.pdf
void print_to_file(std::vector<std::vector<int>> const connected_components, std::string filename)
{
    std::ofstream res_txt;
    res_txt.open (filename);

    for (unsigned int i = 0; i < connected_components.size(); ++i)
    {
        unsigned int j;
        for (j = 0; j < connected_components[i].size()-1; ++j)
        {
            res_txt << connected_components[i][j] << " ";
        }
        res_txt << connected_components[i][j];
        res_txt << "\n";
    }
    res_txt.close();
}

int main(int argc, char *argv[]) {

    utility::SetVerbosityLevel(utility::VerbosityLevel::Debug);
    if (argc != 3) {
        utility::LogInfo("Open3D {}\n", OPEN3D_VERSION);
        utility::LogInfo("\n");
        utility::LogInfo("Usage:\n");
        utility::LogInfo("    > Solution [ .ply filename] [result_filename]\n");
        return 0;
    }
    geometry::TriangleMesh mesh;

    if (io::ReadTriangleMeshFromPLY(argv[1],mesh,0)){
        utility::LogInfo("Successfully read {}\n", argv[2]);
    } else {
        utility::LogError("Failed to read {}\n\n", argv[2]);
        return 1;
    }
    auto connected_components = mesh.IdenticallyColoredConnectedComponents();
    print(connected_components);
    print_to_file(connected_components,argv[2]);
    return 0;
}

/* =========================================================================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

#pragma once

namespace BinaryData
{
    extern const char*   Background_5_1_Semi_Final_png;
    const int            Background_5_1_Semi_Final_pngSize = 167158;

    extern const char*   Background_7_1_Semi_Final_png;
    const int            Background_7_1_Semi_Final_pngSize = 187697;

    extern const char*   Background_Octophonic_Semi_Final_png;
    const int            Background_Octophonic_Semi_Final_pngSize = 174516;

    extern const char*   Background_Quad_Semi_Final_png;
    const int            Background_Quad_Semi_Final_pngSize = 154290;

    extern const char*   Background_Stereo_Semi_Final_png;
    const int            Background_Stereo_Semi_Final_pngSize = 133137;

    extern const char*   Inviro_Coming_soon_png;
    const int            Inviro_Coming_soon_pngSize = 114021;

    // Number of elements in the namedResourceList and originalFileNames arrays.
    const int namedResourceListSize = 6;

    // Points to the start of a list of resource names.
    extern const char* namedResourceList[];

    // Points to the start of a list of resource filenames.
    extern const char* originalFilenames[];

    // If you provide the name of one of the binary resource variables above, this function will
    // return the corresponding data and its size (or a null pointer if the name isn't found).
    const char* getNamedResource (const char* resourceNameUTF8, int& dataSizeInBytes);

    // If you provide the name of one of the binary resource variables above, this function will
    // return the corresponding original, non-mangled filename (or a null pointer if the name isn't found).
    const char* getNamedResourceOriginalFilename (const char* resourceNameUTF8);
}

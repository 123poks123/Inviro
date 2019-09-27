/* =========================================================================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

#pragma once

namespace BinaryData
{
    extern const char*   Easy_background_draft_png;
    const int            Easy_background_draft_pngSize = 25204;

    extern const char*   Background_Quad_Draft_png;
    const int            Background_Quad_Draft_pngSize = 143390;

    extern const char*   Background_Octophonic_Draft_png;
    const int            Background_Octophonic_Draft_pngSize = 163611;

    extern const char*   Background_Stereo_Draft_png;
    const int            Background_Stereo_Draft_pngSize = 121705;

    // Number of elements in the namedResourceList and originalFileNames arrays.
    const int namedResourceListSize = 4;

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

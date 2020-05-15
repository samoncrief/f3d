![F3D Logo](logo.png)

# F3D - Fast and minimalist 3D viewer

By [Kitware SAS](https://www.kitware.eu), 2019

F3D (pronounced `/fɛd/`) is a [VTK-based](https://vtk.org) 3D viewer following the [KISS principle](https://en.wikipedia.org/wiki/KISS_principle), so it is minimalist, efficient, has no GUI,
has simple interaction mechanisms and is fully controllable using arguments in the command line.

It is open-source and cross-platform (tested on Windows, Linux, and macOS).
It supports a range of file formats, rendering and texturing options.

![F3D Demo](../gallery/01-f3d.png)
*A typical render by F3D*

# File formats

Here is the list of supported file formats:
* **.vtk** : the legacy VTK format
* **.vt*** : XML based VTK formats
* **.ply** : Polygon File format
* **.stl** : Standard Triangle Language format
* **.dcm** : DICOM file format
* **.nrrd/.nhrd** : "nearly raw raster data" file format
* **.mhd/.mha** : MetaHeader MetaIO file format
* **.gml** : CityGML file format
* **.pts** : Point Cloud file format
* **.obj** : Wavefront OBJ file format (full scene)
* **.gltf/.glb** : GL Transmission Format (full scene)
* **.3ds** : Autodesk 3DS Max file format (full scene)
* **.wrl** : VRML file format (full scene)

# Scene construction

The **full scene** formats (gltf/glb, 3ds, wrl, obj) contain not only *geometry*, but also scene information like *lights*, *cameras*, *actors* in the scene and *textures* properties.
By default, all this information will be loaded from the file and displayed.
For file formats that do not support it, **a default scene** will be provided.

# Options

## Generic Options
Options &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|Description
------|------
--input=&lt;file&gt;|The *input* file or files to read, can also be provided as a positional argument.
-o, --output=&lt;png file&gt;|Instead of showing a render view and render into it, *render directly into a png file*.
-h, --help|Print *help*.
-v, --verbose|Enable *verbose* mode.
--no-render|Verbose mode without any rendering for the first provided file, to recover information about a file.
--version|Show *version* information.
-x, --axis|Show *axes* as a trihedron in the scene.
-g, --grid|Show *a grid* aligned with the XZ plane.
-e, --edges|Show the *cell edges*.
--progress|Show a *progress bar* when loading the file.
-m, --geometry-only|For certain **full scene** file formats (gltf/glb and obj),<br>reads *only the geometry* from the file and use default scene construction instead.

## Material options
Options&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|Default|Description
------|------|------
-o, --point-sprites||Show sphere *points sprites* instead of the geometry.
--point-size|10.0|Set the *size* of points when showing vertices and point sprites.
--color=<R,G,B>|1.0, 1.0, 1.0| Set a *color* on the geometry.<br>This only makes sense when using the default scene.
--opacity=&lt;opacity&gt;|1.0|Set *opacity* on the geometry.<br>This only makes sense when using the default scene. Usually used with Depth Peeling option.
--roughness=&lt;roughness&gt;|0.3|Set the *roughness coefficient* on the geometry (0.0-1.0).<br>This only makes sense when using the default scene.
--metallic=&lt;metallic&gt;|0.0|Set the *metallic coefficient* on the geometry (0.0-1.0).<br>This only makes sense when using the default scene.
--hrdi=&lt;file path&gt;||Set the *HDRI* image used to create the environment.<br>The environment act as a light source and is reflected on the material.<br>Valid file format are hdr, png, jpg, pnm, tiff, bmp.

## PostFX (OpenGL) options:
Options &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|Description
------|------
-p, --depth-peeling|Enable *depth peeling*. This is a technique used to correctly render translucent objects.
-u, --ssao|Enable *Screen-Space Ambient Occlusion*. This is a technique used to improve the depth perception of the object.
-f, --fxaa|Enable *Fast Approximate Anti-Aliasing*. This technique is used to reduce aliasing.
-a, --tone-mapping|Enable generic filmic *Tone Mapping Pass*. This technique is used to map colors properly to the monitor colors.

## Camera configuration options:
Options &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|Description
------|------
--camera-position=<X,Y,Z>|The position of the camera. Automaticaly computed or recovered from the file if not provided.
--camera-focal-point=<X,Y,Z>|The focal point of the camera. Automaticaly computed or recovered from the file if not provided.
--camera-view-up=<X,Y,Z>|The focal point of the camera. Will be orthogonalized even when provided. Automaticaly computed or recovered from the file if not provided.
--camera-view-angle=&lt;angle&gt;|The view angle of the camera, non-zero value in degrees. Automaticaly computed or recovered from the file if not provided.

## Raytracing options:
Options &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|Default|Description
------|------|------
-r, --raytracing||Enable *OSPRay raytracing*. Requires OSPRay raytracing to be enabled in the linked VTK.
--samples=&lt;samples&gt;|5|The number of *samples per pixel*. It only makes sense with raytracing enabled.
-d, --denoise||*Denoise* the image. It only makes sense with raytracing enabled.

## Scientific visualization options:
Options &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|Default|Description
------|------|------
-s, --scalars=<array_name>||*Color by a specific scalar* array present in the file. If no array_name is provided, one will be picked if any are available. <br>This only makes sense when using the default scene.<br>Use verbose to recover the usable array names.
--comp=<comp_index>|-1|Specify the *component from the scalar* array to color with.<br>Use with the scalar option. Any negative value means *magnitude*.
-c, --cells||Specify that the scalar array is to be found *on the cells* instead of on the points.<br>Use with the scalar option.
--range=<min,max>||Set a *custom range for the coloring* by the array.<br>Use with the scalar option.
-b, --bar||Show *scalar bar* of the coloring by array.<br>Use with the scalar option.
--colormap=<color_list>||Set a *custom colormap for the coloring*.<br>This is a list of colors in the format `val1,red1,green1,blue1,...,valN,redN,greenN,blueN`<br>where all values are in the range (0,1).<br>Use with the scalar option.

## Testing options:
Options|Description
------|------
--ref=&lt;png file&gt;|Reference *image to compare with* for testing purposes.
--ref-threshold=&lt;threshold&gt;|*Testing threshold* to trigger a test failure or success.

## Window options:
Options|Default|Description
------|------|------
--bg-color=<R,G,B>|0.2, 0.2, 0.2|Set the window *background color*.<br>Ignored if *hdri* is set.
--resolution=<width,height>|1000, 600|Set the *window resolution*.
-t, --timer||Display a *frame per second counter*.
-n, --filename||Display the *name of the file*.

# Interaction

Simple interaction with the displayed data is possible directly within the window. It is as follows:
* *Click and drag* with the *left* mouse button to rotate around the focal point of the camera.
* *Click and drag* vertically with the *right* mouse button to zoom in/out.
* *Move the mouse wheel* to zoom in/out.
* *Click and drag* with the *middle* mouse button to translate the camera.
* Press `Return` key to reset the camera to its inital parameters.
* Press `Escape` key to close the window and quit F3D.
* Press `Left/Right` to load the next/previous file if any
* Drag and Drop a file to load it

Some options can be toggled directly using interactions:
* Press `x` key to toggle the trihedral axes display.
* Press `g` key to toggle the XZ grid display.
* Press `e` key to toggle the display of cell edges.
* Press `s` key to toggle the coloration by scalar.
* Press `b` key to toggle the display of the scalar bar, only when coloring with scalars.
* Press `t` key to toggle the display of the FPS counter.
* Press `n` key to toggle the display of the file name.
* Press `r` key to toggle raytracing.
* Press `d` key to toggle the denoiser when raytracing.
* Press `p` key to toggle depth peeling.
* Press `u` key to toggle Screen-Space Ambient Occlusion.
* Press `f` key to toggle Fast Approximate Anti-Aliasing.
* Press `a` key to toggle tone mapping.
* Press `o` key to toggle point sprites rendering.
* Press `l` key to toggle full screen.
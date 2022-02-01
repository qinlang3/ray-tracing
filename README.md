# Computer Graphics – Ray Tracing


![Running `./raytracing ../data/sphere-and-plane.json` should produce this image.](images/sphere-and-plane.png)

![It is recommended to add and debug each term in your shading model. The
ambient term will look like a faint object-ID image. The diffuse term will
illuminate the scene, and create a dull, Lambertian look to each object. The
specular term will add shiny highlights. Then, mask the diffuse and specular
terms by checking for shadows. Finally, add a recursive call to account for
mirror reflections.](images/sphere-and-plane.gif)

![Running `./raytracing ../data/bunny.json` should produce this image.
Notice the ["burned out"](https://en.wikipedia.org/wiki/Burned_(image)) white
regions where the collected light has been clamped to \[1,1,1\]
(white).](images/bunny.png)

![`./raytracing ../data/sphere-packing.json` should produce this
image of highly reflective, metallic looking
surfaces.](images/sphere-packing.png)

>
> ```
> mkdir build-release
> cd build-release
> cmake ../ -DCMAKE_BUILD_TYPE=Release
> make
> ```

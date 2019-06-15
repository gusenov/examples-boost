# WARNING!

[Boost.PropertyTree is not for serializing data!](https://stackoverflow.com/questions/46798811/binary-data-serialization-into-json-with-the-boost-property-tree#comment80544632_46798811)

It's for storing options and so forth; stop using it as a quick-and-dirty JSON parser or serialization library.

Use the right tool for the right job.

You can find C++ JSON libraries easily; they don't have to be part of Boost.

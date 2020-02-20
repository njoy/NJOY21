---
layout: page
title: Metaconfigure
---
## [Updating metaconfigure in a project](Updating.html)

## Creating signatures
Metaconfigure has the ability to create a "signature" for a project. A signature is a unique combination of the project and each of its dependencies---with their specific versions. The signature enables the ability to load a project from a point in time and ensure that you have the same version you had then.

To create a signature simply execute

```bash
./metaconfigure/signature.py <filename>
  ```
This will create a JSON file that contains the signature for the project as it currently stands. The `<filename>` is optional, but allows you to specify the JSON filename that is written.

### Collecting signatures
A signature file is not automatically created. If one would like to be able to recreate a version at a specific time, you must create the signature file yourself.

We have created and stored some signatures in a [repository](https://github.com/njoy/signatures) on GitHub. These signatures are created every time the `master` branch is updated. Thus, it is a collection of officially supported versions of the projects.

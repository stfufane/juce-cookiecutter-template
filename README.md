# Juce Cookiecutter Template

This is a cookiecutter template for creating a [JUCE](https://github.com/juce-framework/JUCE) project with a CMake build system.

[Cookiecutter](https://cookiecutter.readthedocs.io/en/latest/) is a command-line utility that creates projects from cookiecutters (project templates).

![JUCE logo](<{{ cookiecutter.__project_slug }}/data/img/logo.png>)

## Features

- Takes care of the boilerplate
- Downloads JUCE from github
- Offers customization options
- Ready to build/run with CMake
- Contains a basic GUI example (optional)

## Usage

1. [Install cookiecutter](https://cookiecutter.readthedocs.io/en/latest/README.html#installation)

2. Create a new project:

```bash
cookiecutter gh:stfufane/juce-template-cookiecutter
```

3. Open the generated project and follow the instructions in the README


## TODO

- [x] BinaryData (example with juce logo)
- [x] Optional extra components (GUI, ear protection)
- [ ] Add a basic lookandfeel for the slider and toggle button
- [ ] Display the image from BinaryData in the GUI example
- [ ] Handle plugin types and formats

## Credits

Thanks to [Jan Wilczek](https://github.com/JanWilczek), [Eyal Amir](https://github.com/eyalamirmusic/) and [Robbert van der Helm](https://github.com/robbert-vdh) who inspired this template :)
# wxWidgets Tempest

This repository is a collection of projects used against the wxWidgets platform-independent way of developing windowed applications.

### Notes

wxWidgets is a Git submodule to this project.

```
$ git submodule add https://github.com/wxWidgets/wxWidgets
$ git commit -am "Add wxWidgets module"
$ git push origin master
```


### Git Setup

Store the Git repository with text compatible to Linux but modify CRLF when checking out on a Windows platform:

$ git config core.autocrif true
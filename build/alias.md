# Leevel Framework Alias

modify this file ../.git/config add alias and remote,then using git testspull and testspush to manager your subtree repository.

```
git testspull
git testspush // do not allowed,see `tests/README.md`.
```

The code below need to be add.

```
[core]
    repositoryformatversion = 0
    filemode = true
    bare = false
    logallrefupdates = true
    ignorecase = true
    precomposeunicode = true
[remote "origin"]
    url = git@github.com:hunzhiwange/leevel.git
    fetch = +refs/heads/*:refs/remotes/origin/*
[branch "master"]
    remote = origin
    merge = refs/heads/master

[remote "origin"]
        url = git@gitee.com:dyhb/queryyetsimple.git
        fetch = +refs/heads/*:refs/remotes/origin/*

[remote "tests"]
    url = git@github.com:queryyetsimple/tests.git
    fetch = +refs/heads/*:refs/remotes/tests/*

[alias]      
    testspull = !git subtree pull --prefix=tests tests master \
        && :

    testspush = !git subtree split --rejoin --prefix=tests master \
        && git subtree push --prefix=tests tests master \
        && :
```

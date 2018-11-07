# NJOY21 --- NJOY for the 21st Century
The `gh-pages` branch of the NJOY21 repository contains the documentation for NJOY21. 

## Website code
The design of the website is based on code that is contained in the [jekyll-website](https://github.com/njoy/jekyll-website) repository. This should be a remote of this repository where the `master` branch of `jekyll-website` should be duplicated here.

```bash
git remote add jekyll git@github.com:njoy/jekyll-website.git
```

Once the remote has been added, you can pull in the changes like this:
```bash
git pull jekyll master --squash --allow-unrelated-histories
```

## LICENSE
This software is copyrighted by Los Alamos National Laboratory and distributed according to the conditions in the accompanying [LICENSE](LICENSE) file. 

A simple utility to generate your licenses for your new repository, 
because copying and pasting is outdated.

## Supported Licenses
1. MIT
2. BSD 2 Clause
3. Bsd 3 Clause

## Install
``` sh
git clone https://github.com/raynei86/genlicense
cd genlicense
sudo make install
```

## Usage

``` sh
usage: genlicense [-l license] [-a authors] [-d date]

genlicense -l mit -a "John Doe and Jane Doe" -d 2022
genlicense -l mit -a John Doe and Jane Doe -d 2022 
# The two is equivalent
```

## Credits
Heavily inspired by [legit](https://github.com/captainsafia/legit) and [mklicense](https://github.com/cezaraugusto/mklicense).

I rewrote in C because Javascript bad!!11!

### Afternote
Something as simple as this can probably be rewritten in shell script,
I'd be happy to know if someone more well versed in shell than me did it.

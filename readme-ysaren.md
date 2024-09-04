# Quantum Mechanical Keyboard Firmware

This is my fork of the QMK firmware. The two keyboards that it includes are:
- Corne
- Sofle
There is also a userspace for the shared libraries (users/ysaren)

Branch structure:

master-upstream -> master-upstream-ysaren -> master -> develop

- master-upstream        - represents a clean of the upstream QMK repo
- master-upstream-ysaren - created from master-upstream, unused keyboards removed
- master   - created from master-upstream-ysaren, default stable branch, tested on all supported keyboards (temporarily called master-restart)
- develop  - created from master, default development branch

## Build instructions
For converters see: https://docs.qmk.fm/#/feature_converters?id=converters

#### regression testing
- test combo (q+w)
- test numword
- test oneshot modifiers (ctrl+esc)
- test capsword (double tap shift)

### Corne

make crkbd:ysaren -e CONVERT_TO=elite_pi
qmk compile -kb crkbd/rev2 -km ysaren -e CONVERT_TO=elite_pi

### Sofle

make sofle/rev2:ysaren -e CONVERT_TO=elite_pi
(or alternatively)
qmk compile -kb sofle/rev2 -km ysaren -e CONVERT_TO=elite_pi

## Git shananigans

### submodules don't work
git reset --hard origin/[branch]
git submodule update --init --recursive 

(alternatives that sometimes worked)
git submodule update --recursive --remote
git submodule update --force --init --recursive --remote
qmk git-submodule
make git-submodule

cd {submodule path}
git reset --hard origin/master
cd -
git clean -n
git add {submodule path}
git commit
git submodule update --init --recursive

### merge QMK upstream updates
git fetch upstream
git checkout master-upstream
git pull
git rebase upstream/master
git push

git checkout master-minimal
git rebase master-upstream
(note: maybe merge will be better?)
   ./remove-unused-keyboards.ps1
   git rebase --continue
git push

git checkout master
git merge master-ysaren
git push

git checkout develop
git merge master
git push




[![Current Version](https://img.shields.io/github/tag/qmk/qmk_firmware.svg)](https://github.com/qmk/qmk_firmware/tags)
[![Discord](https://img.shields.io/discord/440868230475677696.svg)](https://discord.gg/Uq7gcHh)
[![Docs Status](https://img.shields.io/badge/docs-ready-orange.svg)](https://docs.qmk.fm)
[![GitHub contributors](https://img.shields.io/github/contributors/qmk/qmk_firmware.svg)](https://github.com/qmk/qmk_firmware/pulse/monthly)
[![GitHub forks](https://img.shields.io/github/forks/qmk/qmk_firmware.svg?style=social&label=Fork)](https://github.com/qmk/qmk_firmware/)

This is a keyboard firmware based on the [tmk\_keyboard firmware](https://github.com/tmk/tmk_keyboard) with some useful features for Atmel AVR and ARM controllers, and more specifically, the [OLKB product line](https://olkb.com), the [ErgoDox EZ](https://ergodox-ez.com) keyboard, and the Clueboard product line.

## Documentation

* [See the official documentation on docs.qmk.fm](https://docs.qmk.fm)

The docs are powered by [Docsify](https://docsify.js.org/) and hosted on [GitHub](/docs/). They are also viewable offline; see [Previewing the Documentation](https://docs.qmk.fm/#/contributing?id=previewing-the-documentation) for more details.

You can request changes by making a fork and opening a [pull request](https://github.com/qmk/qmk_firmware/pulls), or by clicking the "Edit this page" link at the bottom of any page.

## Supported Keyboards

* [Planck](/keyboards/planck/)
* [Preonic](/keyboards/preonic/)
* [ErgoDox EZ](/keyboards/ergodox_ez/)
* [Clueboard](/keyboards/clueboard/)
* [Cluepad](/keyboards/clueboard/17/)
* [Atreus](/keyboards/atreus/)

The project also includes community support for [lots of other keyboards](/keyboards/).

## Maintainers

QMK is developed and maintained by Jack Humbert of OLKB with contributions from the community, and of course, [Hasu](https://github.com/tmk). The OLKB product firmwares are maintained by [Jack Humbert](https://github.com/jackhumbert), the Ergodox EZ by [ZSA Technology Labs](https://github.com/zsa), the Clueboard by [Zach White](https://github.com/skullydazed), and the Atreus by [Phil Hagelberg](https://github.com/technomancy).

## Official Website

[qmk.fm](https://qmk.fm) is the official website of QMK, where you can find links to this page, the documentation, and the keyboards supported by QMK.

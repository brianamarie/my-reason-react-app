# My ReasonReact App

## Installing

You can install all the needed dependencies by running `yarn`.

## Watcher

```sh
$ yarn start

yarn run v1.12.3
$ bsb -make-world -w
ninja: no work to do.
ninja: no work to do.
>>>> Start compiling
ninja: no work to do.
>>>> Finish compiling 12 mseconds
```

## Building and Bundling

```sh
$ yarn build

yarn run v1.12.3
$ bsb -make-world && fpack build ./lib/js/src/index.bs.js --development
ninja: no work to do.
ninja: no work to do.
ninja: no work to do.
Cache: used
Done in 0.040s. Bundle: 910Kb. Modules: 16.

✨  Done in 0.30s.
```

## Testing

```sh
$ yarn test

yarn run v1.12.3
$ bsb -make-world && jest
ninja: no work to do.
ninja: no work to do.
ninja: no work to do.
PASS  lib/js/__tests__/model_test.bs.js
 some test
     ✓ passes! (5ms)

Test Suites: 1 passed, 1 total
Tests:       1 passed, 1 total
Snapshots:   0 total
Time:        1.572s
Ran all test suites.
✨  Done in 2.81s.
```

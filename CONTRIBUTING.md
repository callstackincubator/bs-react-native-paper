# Contributing to Bs React Native Paper

## Code of Conduct

We want this community to be friendly and respectful to each other. Please read [the full text](/CODE_OF_CONDUCT.md) so that you can understand what actions will and will not be tolerated.

## Our Development Process

The core team works directly on GitHub and all work is public.

### Development workflow

> **Working on your first pull request?** You can learn how from this _free_ series: [How to Contribute to an Open Source Project on GitHub](https://egghead.io/series/how-to-contribute-to-an-open-source-project-on-github).

1.  Fork the repo and create your branch from `master` (a guide on [how to fork a repository](https://help.github.com/articles/fork-a-repo/)).
2.  Run `yarn bootstrap` to setup the developement environment.
3.  Do the changes you want and test them out in the example app before sending a pull request.

### Commit message convention

We prefix our commit messages with one of the following to signify the kind of change:

* `fix`: bug fixes, e.g. fix Button color on DarkTheme.
* `feat`: new features, e.g. bindings to new component.
* `refactor`: code/structure refactor, e.g. new structure folder for components.
* `test`: adding or updating tests, eg unit testing.
* `chore`: tooling changes, e.g. change circle ci config.
* `BREAKING`: for changes that break existing usage, e.g. change API of a component.

### Sending a pull request

When you're sending a pull request:

* Prefer small pull requests focused on one change.
* Follow the pull request template when opening a pull request.

### Running the example

The example app uses [Expo](https://expo.io/). You will need to install the Expo app for [Android](https://play.google.com/store/apps/details?id=host.exp.exponent) and [iOS](https://itunes.apple.com/app/apple-store/id982107779) to start developing.

After you're done, you can run `yarn start` in the `example/` folder and scan the QR code to launch it on your device.

## Reporting issues

You can report issues on our [bug tracker](https://github.com/callstackincubator/bs-react-native-paper/issues). Please follow the issue template when opening an issue.

## License

By contributing to Bs React Native Paper, you agree that your contributions will be licensed under its **MIT** license.

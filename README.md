[![Build Status][build-badge]][build]
[![Version][version-badge]][package]
[![MIT License][license-badge]][license]
[![PRs Welcome][prs-welcome-badge]][prs-welcome]
[![Chat][chat-badge]][chat]

# bs-react-native-paper

[React Native Paper bindings](https://github.com/callstack/react-native-paper) for BS

```ocaml
<Paper.Button onPress=((_event) => yourAction())>
  <Paper.Text>
    (ReasonReact.string("Click me"))
  </Paper.Text>
</Paper.Button>
```

```ocaml
<Paper.FABGroup
  actions=Paper.FABGroup.[|
    fabAction(~icon="add", ~onPress=() => Js.log("add"), ()),
    fabAction(~icon="star", ~onPress=() => Js.log("start"), ()),
    fabAction(~icon="notifications",  ~onPress=() => Js.log("notifications"), ()),
  |]
  onStateChange
/>
```

## Installation

Use yarn or npm

```
$ yarn add bs-react-native-paper react-native-paper
```

Then add `bs-react-native-paper` to `bsconfig.json`

```json
"bs-dependencies": ["bs-react-native-paper"]
```

## Using theme

```ocaml
/* We provide a helper function called `createTheme` that defaults with DefaultTheme */
let theme =
  Paper.ThemeProvider.(
    createTheme(
      ~colors=
        themeColors(
          ~primary="blue",
          ~accent="blue",
          ~background="white",
          ~paper="blue",
          ~text="black",
          ~disabled="gray",
          ~placeholder="gray",
        ),
      (),
    )
  );

let component = ReasonReact.statelessComponent("AppTheme");

let make = children => {
  ...component,
  render: _self =>
    <Paper.ThemeProvider theme>
      (ReasonReact.array(children))
    </Paper.ThemeProvider>,
};
```

## Contributing

Read the [contribution guidelines](/CONTRIBUTING.md) before contributing.

<!-- badges -->

[build-badge]: https://img.shields.io/circleci/project/github/callstackincubator/bs-react-native-paper/master.svg?style=flat-square
[build]: https://circleci.com/gh/callstackincubator/bs-react-native-paper
[version-badge]: https://img.shields.io/npm/v/bs-react-native-paper.svg?style=flat-square
[package]: https://www.npmjs.com/package/bs-react-native-paper
[license-badge]: https://img.shields.io/npm/l/bs-react-native-paper.svg?style=flat-square
[license]: https://opensource.org/licenses/MIT
[prs-welcome-badge]: https://img.shields.io/badge/PRs-welcome-brightgreen.svg?style=flat-square
[prs-welcome]: http://makeapullrequest.com
[chat-badge]: https://img.shields.io/discord/426714625279524876.svg?style=flat-square&colorB=758ED3
[chat]: https://discord.gg/zwR2Cdh

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
$ yarn add bs-react-native-paper react-native-paper rebolt
```

Then update your `bsconfig.json`

```json
"bs-dependencies": ["reason-react", "rebolt", "bs-react-native-paper"]
```

## Using theme
```ocaml

/* We provide a help function called `createTheme` that defaults with DefaultTheme */
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

## Bindings
- [ ] Icons (Use https://github.com/Astrocoders/bs-react-native-vector-icons instead)
- [ ] Chip
- [x] List
- [x] ListItem
- [x] ListSection
- [x] ListAccordion
- [x] Button
- [x] Caption
- [x] Card
- [x] CardActions
- [x] CardContent
- [x] CardCover
- [x] Checkbox
- [x] Dialog
- [x] DialogActions
- [x] DialogContent
- [x] DialogScrollArea
- [x] DialogTitle
- [x] Divider
- [x] DrawerItem
- [x] DrawerSection
- [x] FAB
- [x] FABGroup
- [x] Headline
- [x] Modal
- [x] Paper
- [x] Paragraph
- [x] ProgressBar
- [x] RadioButton
- [x] SearchBar
- [x] Subheading
- [x] Switch
- [ ] Snackbar
- [x] Text
- [x] TextInput
- [x] ThemeProvider
- [x] Title
- [x] Toolbar
- [x] ToolbarAction
- [x] ToolbarBackAction
- [x] ToolbarContent
- [x] TouchableRipple

## License

MIT

## Contributing
PR are welcome!

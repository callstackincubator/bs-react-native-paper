open Paper;
open BsReactNative;
open ReboltNavigation;

let getCurrentScreen = (p: Header.props) => p.screens[p.activeScreen];

let component = ReasonReact.statelessComponent("PaperHeader");

let make = (~headerProps: Header.props, _children) => {
  ...component,
  render: _self => {
    let currentScreen = getCurrentScreen(headerProps);

    <Appbar.Header>
      {
        headerProps.activeScreen === 0 ?
          ReasonReact.null :
          <Appbar.BackAction
            onPress={_event => headerProps.pop(currentScreen.key)}
          />
      }
      <Appbar.Content
        title={
          (
            switch (currentScreen.header.title) {
            | Some(title) => title
            | None => "Header"
            }
          )
          |> ReasonReact.string
        }
      />
    </Appbar.Header>;
  },
};

open BsReactNative;
open Navigation;

module Styles = {
  open Style;

  let container =
    style([flex(1.), justifyContent(Center), alignItems(Center)]);
};

let theme =
  Paper.ThemeProvider.(
    createTheme(
      ~colors=
        themeColors(
          ~primary="#6200EE",
          ~accent="tomato",
          ~background="white",
          ~surface="white",
          ~text="black",
          ~disabled="gray",
          ~placeholder="gray",
          ~backdrop="black",
        ),
      (),
    )
  );

let component = ReasonReact.statelessComponent("App");

let make = _children => {
  ...component,
  render: _self =>
    <Paper.PaperProvider>
      <Paper.ThemeProvider theme>
        <StackNavigator
          initialState=[|Config.Home|] headerComponent=Header.make>
          ...{
               (~currentRoute, ~navigation) =>
                 switch (currentRoute) {
                 | Config.Home => <Home navigation />
                 | Config.SnackbarExample => <SnackbarExample navigation />
                 | Config.SurfaceExample => <SurfaceExample navigation />
                 | Config.TypographyExample => <TypographyExample navigation />
                 }
             }
        </StackNavigator>
      </Paper.ThemeProvider>
    </Paper.PaperProvider>,
};

let reactClass =
  ReasonReact.wrapReasonForJs(~component, _jsProps => make([||]));

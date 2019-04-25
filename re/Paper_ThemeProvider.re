[@bs.deriving abstract]
type themeColors = {
  primary: string,
  accent: string,
  background: string,
  surface: string,
  error: string,
  text: string,
  disabled: string,
  placeholder: string,
  backdrop: string,
};

[@bs.deriving abstract]
type themeFonts = {
  [@bs.optional]
  regular: string,
  [@bs.optional]
  medium: string,
  [@bs.optional]
  light: string,
  [@bs.optional]
  thin: string,
};

[@bs.deriving abstract]
type appTheme = {
  roundness: int,
  dark: bool,
  colors: themeColors,
  fonts: themeFonts,
};

[@bs.module "react-native-paper"]
external defaultTheme: appTheme = "DefaultTheme";

[@bs.module "react-native-paper"] external darkTheme: appTheme = "DarkTheme";

let createTheme =
    (
      ~roundness=roundnessGet(defaultTheme),
      ~dark=darkGet(defaultTheme),
      ~colors=colorsGet(defaultTheme),
      ~fonts=fontsGet(defaultTheme),
      (),
    ) =>
  appTheme(~roundness, ~dark, ~colors, ~fonts);

[@bs.module "react-native-paper"] [@react.component]
external make: (~theme: appTheme=?) => React.element = "ThemeProvider";

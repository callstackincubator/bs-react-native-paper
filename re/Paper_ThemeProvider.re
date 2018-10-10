[@bs.module "react-native-paper"]
external reactClass: ReasonReact.reactClass = "ThemeProvider";

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

[@bs.deriving abstract]
type props = {
  [@bs.optional]
  theme: appTheme,
};

let createTheme =
    (
      ~roundness=roundnessGet(defaultTheme),
      ~dark=darkGet(defaultTheme),
      ~colors=colorsGet(defaultTheme),
      ~fonts=fontsGet(defaultTheme),
      (),
    ) =>
  appTheme(~roundness, ~dark, ~colors, ~fonts);

let make = (~theme=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=props(~theme?, ()),
    children,
  );

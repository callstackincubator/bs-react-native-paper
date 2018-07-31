[@bs.module "react-native-paper"]
external reactClass : ReasonReact.reactClass = "ThemeProvider";

[@bs.deriving abstract]
type themeColors = {
  primary: string,
  accent: string,
  background: string,
  paper: string,
  text: string,
  disabled: string,
  placeholder: string,
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
  [@bs.optional]
  roundess: int,
  [@bs.optional]
  dark: bool,
  [@bs.optional]
  colors: themeColors,
};

[@bs.deriving abstract]
type props = {
  [@bs.optional]
  theme: appTheme,
};

let make = (~theme=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=props(~theme?, ()),
    children,
  );

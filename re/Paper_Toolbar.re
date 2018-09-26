[@bs.module "react-native-paper"]
external reactClass: ReasonReact.reactClass = "Toolbar";

let make =
    (
      ~dark: bool=false,
      ~statusBarHeight: option(float)=?,
      ~theme: option(Paper_ThemeProvider.appTheme)=?,
      ~style: option(BsReactNative.Style.t)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Null_undefined.{
        "dark": dark,
        "statusBarHeight": fromOption(statusBarHeight),
        "theme": fromOption(theme),
        "style": fromOption(style),
      },
    children,
  );

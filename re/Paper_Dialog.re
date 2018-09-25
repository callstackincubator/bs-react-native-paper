[@bs.module "react-native-paper"]
external reactClass: ReasonReact.reactClass = "Dialog";

let make =
    (
      ~dismissable: bool=false,
      ~visible: bool=false,
      ~theme: option(Paper_ThemeProvider.appTheme)=?,
      ~style: option(BsReactNative.Style.t)=?,
      ~onDismiss: option(unit => unit),
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Null_undefined.{
        "dismissable": dismissable,
        "visible": visible,
        "style": fromOption(style),
        "theme": fromOption(theme),
        "onDismiss": fromOption(onDismiss),
      },
    children,
  );

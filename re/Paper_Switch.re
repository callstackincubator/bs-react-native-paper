[@bs.module "react-native-paper"]
external reactClass: ReasonReact.reactClass = "Switch";

let make =
    (
      ~disabled: bool=false,
      ~value: bool=false,
      ~color: option(string)=?,
      ~theme: option(Paper_ThemeProvider.appTheme)=?,
      ~style: option(BsReactNative.Style.t)=?,
      ~onValueChange: option(bool => unit)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Nullable.{
        "disabled": disabled,
        "value": value,
        "color": fromOption(color),
        "onValueChange": fromOption(onValueChange),
        "theme": fromOption(theme),
        "style": fromOption(style),
      },
    children,
  );

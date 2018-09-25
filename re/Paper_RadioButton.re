[@bs.module "react-native-paper"]
external reactClass: ReasonReact.reactClass = "RadioButton";

let make =
    (
      ~checked: bool=false,
      ~disabled: bool=false,
      ~color: option(string)=?,
      ~theme: option(Paper_ThemeProvider.appTheme)=?,
      ~onPress: option(BsReactNative.RNEvent.NativeEvent.t => unit)=?,
      ~value: string,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Null_undefined.{
        "checked": checked,
        "disabled": disabled,
        "onPress": fromOption(onPress),
        "color": fromOption(color),
        "theme": fromOption(theme),
        "value": value,
      },
    children,
  );

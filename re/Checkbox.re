[@bs.module "react-native-paper"]
external reactClass : ReasonReact.reactClass = "Checkbox";

let make =
  (
    ~checked: option(bool),
    ~theme: option(Js.t({..}))=?,
    ~disabled: option(bool)=?,
    ~color: option(string)=?,
    ~style: option(BsReactNative.Style.t)=?,
    ~onPress: option(BsReactNative.RNEvent.NativeEvent.t => unit)=?,
    children
  ) =>
ReasonReact.wrapJsForReason(
  ~reactClass,
  ~props=
    Js.Nullable.(
      {
        "style": from_opt(style),
        "checked": from_opt(checked),
        "theme": from_opt(theme),
        "onPress": from_opt(onPress),
        "color": from_opt(color),
        "disabled": from_opt(disabled)
      }
    ),
  children
);

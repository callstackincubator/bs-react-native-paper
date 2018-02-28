[@bs.module "react-native-paper"]
external reactClass : ReasonReact.reactClass = "RadioButton";

let make =
  (
    ~checked: option(bool),
    ~disabled: option(bool)=?,
    ~color: option(string)=?,
    ~theme: option(Js.t({..}))=?,
    ~onPress: option(BsReactNative.RNEvent.NativeEvent.t => unit)=?,
    children
  ) =>
ReasonReact.wrapJsForReason(
  ~reactClass,
  ~props=
    Js.Nullable.(
      {
        "checked": from_opt(checked),
        "disabled": from_opt(disabled),
        "onPress": from_opt(onPress),
        "color": from_opt(color),
        "theme": from_opt(theme)
      }
    ),
  children
);

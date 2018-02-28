open Utils;

[@bs.module "react-native-paper"]
external reactClass : ReasonReact.reactClass = "Switch";

let make =
  (
    ~disabled: option(bool)=?,
    ~value: option(bool)=?,
    ~color: option(string)=?,
    ~theme: option(Js.t({..}))=?,
    ~style: option(BsReactNative.Style.t)=?,
    ~onValueChange: option(bool => unit)=?,
    children
  ) =>
ReasonReact.wrapJsForReason(
  ~reactClass,
  ~props=
    Js.Nullable.(
      {
        "disabled": from_opt(disabled),
        "value": from_opt(value),
        "color": from_opt(color),
        "onValueChange": from_opt(onValueChange),
        "theme": from_opt(theme),
        "style": from_opt(style)
      }
    ),
  children
);

open Utils;

[@bs.module "react-native-paper"]
external reactClass : ReasonReact.reactClass = "TouchableRipple";

let make =
  (
    ~borderless: option(bool)=?,
    ~background: option(Js.t({..}))=?,
    ~disabled: option(bool)=?,
    ~rippleColor: option(string)=?,
    ~underlayColor: option(string)=?,
    ~style: option(BsReactNative.Style.t)=?,
    ~theme: option(Js.t({..}))=?,
    ~onPress: option(BsReactNative.RNEvent.NativeEvent.t => unit)=?,
    children
  ) =>
ReasonReact.wrapJsForReason(
  ~reactClass,
  ~props=
    Js.Nullable.(
      {
        "borderless": from_opt(borderless),
        "background": from_opt(background),
        "disabled": from_opt(disabled),
        "rippleColor": from_opt(rippleColor),
        "underlayColor": from_opt(underlayColor),
        "theme": from_opt(theme),
        "onPress": from_opt(onPress),
        "style": from_opt(style)
      }
    ),
  children
);

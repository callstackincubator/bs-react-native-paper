[@bs.module "react-native-paper"]
external reactClass : ReasonReact.reactClass = "FAB";

let make =
  (
    ~small: option(bool)=?,
    ~dark: option(bool)=?,
    ~color: option(string)=?,
    ~theme: option(Js.t({..}))=?,
    ~icon: option(ReasonReact.reactElement),
    ~style: option(BsReactNative.Style.t)=?,
    ~onPress: option(BsReactNative.RNEvent.NativeEvent.t => unit)=?,
    children
  ) =>
ReasonReact.wrapJsForReason(
  ~reactClass,
  ~props=
    Js.Nullable.(
      {
        "small": from_opt(small),
        "dark": from_opt(dark),
        "color": from_opt(color),
        "icon": from_opt(icon),
        "onPress": from_opt(onPress),
        "style": from_opt(style),
        "theme": from_opt(theme)
      }
    ),
  children
);
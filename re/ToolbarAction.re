[@bs.module "react-native-paper"]
external reactClass : ReasonReact.reactClass = "ToolbarAction";

let make =
  (
    ~dark: option(bool)=?,
    ~size: option(float)=?,
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
        "dark": from_opt(dark),
        "size": from_opt(size),
        "icon": from_opt(icon),
        "onPress": from_opt(onPress),
        "style": from_opt(style)
      }
    ),
  children
);

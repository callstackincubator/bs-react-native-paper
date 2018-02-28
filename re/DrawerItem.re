open Utils;

[@bs.module "react-native-paper"]
external reactClass : ReasonReact.reactClass = "DrawerItem";

let make =
  (
    ~label: option(string),
    ~icon: option(ReasonReact.reactElement)=?,
    ~active: option(bool)=?,
    ~theme: option(Js.t({..}))=?,
    ~color: option(string)=?,
    ~onPress: option(BsReactNative.RNEvent.NativeEvent.t => unit)=?,
    children
  ) =>
ReasonReact.wrapJsForReason(
  ~reactClass,
  ~props=
    Js.Nullable.(
      {
        "label": from_opt(label),
        "icon": from_opt(icon),
        "active": from_opt(active),
        "color": from_opt(color),
        "onPress": from_opt(onPress),
        "theme": from_opt(theme)
      }
    ),
  children
);

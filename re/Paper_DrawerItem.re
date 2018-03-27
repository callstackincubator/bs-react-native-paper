[@bs.module "react-native-paper"]
external reactClass : ReasonReact.reactClass = "DrawerItem";

let make =
    (
      ~label: option(string),
      ~icon: option(ReasonReact.reactElement)=?,
      ~active: bool=false,
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
          "label": Js.Undefined.fromOption(label),
          "icon": Js.Undefined.fromOption(icon),
          "active": Js.Boolean.to_js_boolean(active),
          "color": Js.Undefined.fromOption(color),
          "onPress": Js.Undefined.fromOption(onPress),
          "theme": Js.Undefined.fromOption(theme)
        }
      ),
    children
  );

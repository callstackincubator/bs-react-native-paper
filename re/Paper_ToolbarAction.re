[@bs.module "react-native-paper"]
external reactClass : ReasonReact.reactClass = "ToolbarAction";

let make =
    (
      ~dark: bool=false,
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
          "dark": Js.Boolean.to_js_boolean(dark),
          "size": Js.Undefined.fromOption(size),
          "icon": Js.Undefined.fromOption(icon),
          "onPress": Js.Undefined.fromOption(onPress),
          "style": Js.Undefined.fromOption(style)
        }
      ),
    children
  );

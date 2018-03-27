[@bs.module "react-native-paper"]
external reactClass : ReasonReact.reactClass = "ToolbarContent";

let make =
    (
      ~dark: bool=false,
      ~title: option(string),
      ~titleStyle: option(Js.t({..}))=?,
      ~subtitle: option(string)=?,
      ~subtitleStyle: option(Js.t({..}))=?,
      ~theme: option(Js.t({..}))=?,
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
          "onPress": Js.Undefined.fromOption(onPress),
          "title": Js.Undefined.fromOption(title),
          "titleStyle": Js.Undefined.fromOption(titleStyle),
          "subtitle": Js.Undefined.fromOption(subtitle),
          "subtitleStyle": Js.Undefined.fromOption(subtitleStyle),
          "style": Js.Undefined.fromOption(style),
          "theme": Js.Undefined.fromOption(theme)
        }
      ),
    children
  );

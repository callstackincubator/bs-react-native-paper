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
      Js.Null_undefined.(
        {
          "dark": Js.Boolean.to_js_boolean(dark),
          "onPress": from_opt(onPress),
          "title": from_opt(title),
          "titleStyle": from_opt(titleStyle),
          "subtitle": from_opt(subtitle),
          "subtitleStyle": from_opt(subtitleStyle),
          "style": from_opt(style),
          "theme": from_opt(theme)
        }
      ),
    children
  );

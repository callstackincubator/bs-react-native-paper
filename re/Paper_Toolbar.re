[@bs.module "react-native-paper"]
external reactClass : ReasonReact.reactClass = "Toolbar";

let make =
    (
      ~dark: bool=false,
      ~statusBarHeight: option(float)=?,
      ~theme: option(Js.t({..}))=?,
      ~style: option(BsReactNative.Style.t)=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Null_undefined.(
        {
          "dark": Js.Boolean.to_js_boolean(dark),
          "statusBarHeight": from_opt(statusBarHeight),
          "theme": from_opt(theme),
          "style": from_opt(style)
        }
      ),
    children
  );

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
      Js.Nullable.(
        {
          "dark": Js.Boolean.to_js_boolean(dark),
          "statusBarHeight": Js.Undefined.fromOption(statusBarHeight),
          "theme": Js.Undefined.fromOption(theme),
          "style": Js.Undefined.fromOption(style)
        }
      ),
    children
  );

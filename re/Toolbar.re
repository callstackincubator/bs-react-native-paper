open Utils;

[@bs.module "react-native-paper"]
external reactClass : ReasonReact.reactClass = "Toolbar";

let make =
  (
    ~dark: option(bool)=?,
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
        "dark": from_opt(dark),
        "statusBarHeight": from_opt(statusBarHeight),
        "theme": from_opt(theme),
        "style": from_opt(style)
      }
    ),
  children
);

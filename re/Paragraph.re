

[@bs.module "react-native-paper"]
external reactClass : ReasonReact.reactClass = "Paragraph";

let make =
  (
    ~style: option(BsReactNative.Style.t)=?,
    children
  ) =>
ReasonReact.wrapJsForReason(
  ~reactClass,
  ~props=
    Js.Nullable.(
      {
        "style": from_opt(style)
      }
    ),
  children
);

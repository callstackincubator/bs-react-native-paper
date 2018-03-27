[@bs.module "react-native-paper"]
external reactClass : ReasonReact.reactClass = "DialogTitle";

let make =
    (
      ~theme: option(Js.t({..}))=?,
      ~style: option(BsReactNative.Style.t)=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Nullable.(
        {
          "style": Js.Undefined.fromOption(style),
          "theme": Js.Undefined.fromOption(theme)
        }
      ),
    children
  );

[@bs.module "react-native-paper"]
external reactClass : ReasonReact.reactClass = "CardCover";

let make =
    (
      ~theme: option(Js.t({..}))=?,
      ~style: option(Rebolt.Style.t)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Null_undefined.(
        {"style": fromOption(style), "theme": fromOption(theme)}
      ),
    children,
  );

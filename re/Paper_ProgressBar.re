[@bs.module "react-native-paper"]
external reactClass: ReasonReact.reactClass = "ProgressBar";

let make =
    (
      ~progress: option(float),
      ~color: option(string)=?,
      ~theme: option(Js.t({..}))=?,
      ~style: option(ReactNative.Style.t)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Null_undefined.{
        "progress": fromOption(progress),
        "color": fromOption(color),
        "theme": fromOption(theme),
        "style": fromOption(style),
      },
    children,
  );

[@bs.module "react-native-paper"]
external reactClass : ReasonReact.reactClass = "ProgressBar";

let make =
    (
      ~progress: option(float),
      ~color: option(string)=?,
      ~theme: option(Js.t({..}))=?,
      ~style: option(BsReactNative.Style.t)=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Null_undefined.(
        {
          "progress": from_opt(progress),
          "color": from_opt(color),
          "theme": from_opt(theme),
          "style": from_opt(style)
        }
      ),
    children
  );

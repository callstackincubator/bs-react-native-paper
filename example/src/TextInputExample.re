open BsReactNative;
open Navigation;
open BsReactNativePaper;
open Paper;

module Styles = {
  open Style;

  let container =
    style([
      flex(1.0),
      padding(Pt(8.)),
      backgroundColor(String("#ffffff")),
    ]);
  let inputContainerStyle = style([margin(Pt(8.))]);
};

let isUsernameValid = (username: string) =>
  Js.Re.fromString("^[a-zA-Z]*$") |> Js.Re.test(username);

type state = {
  text: string,
  outlinedText: string,
  name: string,
};

type action =
  | TextChanged(string)
  | OutlinedChanged(string)
  | HelperChanged(string);

let component = ReasonReact.reducerComponent("SnackbarExample");

let make = (~navigation: StackNavigator.navigation, _children) => {
  ...component,
  initialState: () => {text: "", outlinedText: "", name: ""},
  reducer: (action, state) =>
    switch (action) {
    | TextChanged(text) => ReasonReact.Update({...state, text})
    | OutlinedChanged(text) =>
      ReasonReact.Update({...state, outlinedText: text})
    | HelperChanged(text) => ReasonReact.Update({...state, name: text})
    },
  render: self =>
    <StackNavigator.Screen headerTitle="Snackbar example" navigation>
      ...{
           () =>
             <ScrollView style=Styles.container>
               <TextInput
                 style=Styles.inputContainerStyle
                 label="Flat input"
                 placeholder="Type something"
                 value={self.state.text}
                 onChangeText={value => self.send(TextChanged(value))}
               />
               <TextInput
                 disabled=true
                 style=Styles.inputContainerStyle
                 label="Disabled flat input"
               />
               <TextInput
                 mode=`outlined
                 style=Styles.inputContainerStyle
                 label="Outlined input"
                 placeholder="Type something"
                 value={self.state.outlinedText}
                 onChangeText={
                   outlinedText => self.send(OutlinedChanged(outlinedText))
                 }
               />
               <TextInput
                 mode=`outlined
                 disabled=true
                 style=Styles.inputContainerStyle
                 label="Disabled outlined input"
               />
               <View style=Styles.inputContainerStyle>
                 <TextInput
                   label="Input with helper text"
                   placeholder="Enter username, only letters"
                   value={self.state.name}
                   error={!isUsernameValid(self.state.name)}
                   onChangeText={name => self.send(HelperChanged(name))}
                 />
                 <HelperText
                   type_=`error visible={!isUsernameValid(self.state.name)}>
                   {ReasonReact.string("Error: Only letters are allowed")}
                 </HelperText>
               </View>
             </ScrollView>
         }
    </StackNavigator.Screen>,
};

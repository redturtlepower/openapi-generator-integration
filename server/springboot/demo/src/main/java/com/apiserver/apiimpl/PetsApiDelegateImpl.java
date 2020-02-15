package com.apiserver.apiimpl;

import org.openapitools.api.PetsApiDelegate;
import org.openapitools.model.Pet;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Component;
import org.springframework.stereotype.Service;

import java.util.List;

@Component
@Service
public class PetsApiDelegateImpl implements PetsApiDelegate {

    @Override
    public ResponseEntity<Void> createPets() {
        return null;
    }

    @Override
    public ResponseEntity<List<Pet>> listPets(Integer limit) {
        return null;
    }

    @Override
    public ResponseEntity<Pet> showPetById(String petId) {
        System.out.println("PetsApiDelegateImpl::showPetById");
        return null;
    }
}
